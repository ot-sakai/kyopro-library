//ABC357-F
struct S {
    mint a;
    mint b;
    mint ab;
    int len;
};

struct F {
    mint a;
    mint b;
};

S op(S a, S b) {
    S res;
    res.ab = a.ab + b.ab;
    res.a = a.a + b.a;
    res.b = a.b + b.b;
    res.len = a.len + b.len;
    return res;
}

S e() {
    return {0, 0, 0, 0};
}

S mapping(F f, S x) {
    return {x.a + f.a * x.len, x.b + f.b * x.len, x.ab + x.a * f.b + x.b * f.a + f.a * f.b * x.len, x.len};
}

F composition(F f, F g) {
    return {g.a + f.a, g.b + f.b};
}

F id() {
    return {0, 0};
}

int main() {
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
}