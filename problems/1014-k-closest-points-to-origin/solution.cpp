class Solution {
private:
    using point = vector<int>;
    struct{
        bool operator() (const point& pa, const point& pb){
            return pa[0] * pa[0] - pb[0] * pb[0] + pa[1] * pa[1] - pb[1] * pb[1] < 0;
        }
    }compare_points;

public:
    vector<point> kClosest(vector<point>& points, int k) {
        sort(points.begin(), points.end(), compare_points);
        return vector<point>{points.begin(), points.begin() + k};
    }
};


