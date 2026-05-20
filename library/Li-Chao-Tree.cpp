//https://sotanishy.github.io/cp-library-cpp/data-structure/cht/li_chao_tree.hpp.html
template <typename T>
class LiChaoTree {
   public:
    LiChaoTree() = default;
    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {
        assert(!xs.empty());
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        size = bit_ceil_int(xs.size());
        node.resize(2 * size, Line(0, INF));
        while ((int)xs.size() <= size) xs.push_back(xs.back() + 1);
    }
 
    void add_line(T a, T b) { update(Line(a, b), 1, 0, size); }
 
    void add_segment(T a, T b, T xl, T xr) {
        int l = (int)(std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin());
        int r = (int)(std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin());
 
        Line line(a, b);
        int len = 1;
        int l0 = l, r0 = r;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {
            if (l & 1) {
                update(line, l++, l0, l0 + len);
                l0 += len;
            }
            if (r & 1) {
                --r;
                r0 -= len;
                update(line, r, r0, r0 + len);
            }
        }
    }
 
    T get(T x) const {
        int k = (int)(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        k += size;
        T res = node[k](x);
        while (k >>= 1) res = std::min(res, node[k](x));
        return res;
    }
 
   private:
    struct Line {
        T a, b;
        Line(T a_, T b_) : a(a_), b(b_) {}
        T operator()(T x) const {
            if (a == 0 && b == INF) return INF;
            return a * x + b;
        }
    };
 
    static constexpr T INF = std::numeric_limits<T>::max();
 
    int size;
    std::vector<T> xs;
    std::vector<Line> node;
 
    // std::bit_ceil(n) の代替: n 以上の最小の 2 のべき
    static int bit_ceil_int(std::size_t n) {
        int s = 1;
        while ((std::size_t)s < n) s <<= 1;
        return s;
    }
 
    void update(Line line, int k, int l, int r) {
        while (true) {
            int m = l + (r - l) / 2;                  // midpoint の代替
            bool left_  = line(xs[l]) < node[k](xs[l]);
            bool mid    = line(xs[m]) < node[k](xs[m]);
            bool right_ = line(xs[r]) < node[k](xs[r]);
 
            if (!left_ && !right_) break;
            if (left_ && right_) {
                node[k] = line;
                break;
            }
            if (mid) std::swap(node[k], line);
            if (r - l == 1) break;
            if (left_ != mid) {
                k = 2 * k;
                r = m;
            } else {
                k = 2 * k + 1;
                l = m;
            }
        }
    }
};