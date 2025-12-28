#include <iostream>
#include <vector>

#define MAX_RADIUS 0.25

using namespace std;

class Convert {
  public:
    vector<float> convert (vector<int> coods) {
      vector<float> res;
      int lar = coods[0];

      for(auto i : coods) {
        if (i > lar) {
          lar = i;
        }
      }

      for(auto i : coods) {
        res.push_back(static_cast<float>(static_cast<double>(i) * (MAX_RADIUS / static_cast<double>(lar))));
      }

      return res;
    }
};
