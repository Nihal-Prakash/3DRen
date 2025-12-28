import json
import re
from pathlib import Path

VS_PATTERN = re.compile(
    r"(const\s+vs\s*=\s*\[)(.*?)(\]\s*;)",
    re.DOTALL
)

FS_PATTERN = re.compile(
    r"(const\s+fs\s*=\s*\[)(.*?)(\]\s*;)",
    re.DOTALL
)

def format_vs(points, decimals=6):
    lines = ["const vs = ["]
    for x, y, z in points:
        lines.append(
            f"    {{x: {x:.{decimals}f}, y: {y:.{decimals}f}, z: {z:.{decimals}f}}},"
        )
    lines.append("];")
    return "\n".join(lines)

def generate_fs_complete(n):
    fs = []
    for i in range(n):
        for j in range(i + 1, n):
            fs.append((i, j))
    return fs

def format_fs(fs):
    lines = ["const fs = ["]
    for i, j in fs:
        lines.append(f"    [{i}, {j}],")
    lines.append("];")
    return "\n".join(lines)

def replace_block(pattern, text, replacement):
    m = pattern.search(text)
    if not m:
        raise RuntimeError("Required block not found")
    start, end = m.span()
    return text[:start] + replacement + text[end:]

def main():
    points = json.loads(Path("points.json").read_text())
    curr_js = Path("curr.js").read_text()

    vs_block = format_vs(points)
    fs_block = format_fs(generate_fs_complete(len(points)))

    curr_js = replace_block(VS_PATTERN, curr_js, vs_block)
    curr_js = replace_block(FS_PATTERN, curr_js, fs_block)

    Path("curr.js").write_text(curr_js)
    print(f"Updated vs ({len(points)} pts) and fs ({len(points)*(len(points)-1)//2} edges)")

if __name__ == "__main__":
    main()

