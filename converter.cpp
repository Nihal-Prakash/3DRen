#include <iostream>
#include <vector>

#define MAX_RADIUS 0.25

using namespace std;

class Convert {
  public:
    vector<double> convert (vector<int> coods) {
      vector<double> res;
      res.reserve(coods.size());

      int maxAbs = 0;
      for(int v : coods) {
        maxAbs = max(maxAbs, abs(v));
      }

      if(maxAbs == 0) {
        res.assign(coods.size(), 0.0f);
        return res;
      }

      const double scale = MAX_RADIUS / static_cast<float>(maxAbs);
      
      for(auto i : coods) {
        res.push_back(static_cast<double>(i) * scale);
      }

      return res;
    }
};
