struct Triple {
    ll d,x,y;
};

Triple extendedEuclid(ll A, ll B) {
    if (B == 0) return {A, 1, 0};
    else {
        Triple ext = extendedEuclid(B, A%B);
        return {ext.d, ext.y, ext.x - (A/B) * ext.y};
    }
}