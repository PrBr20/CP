struct comp {
    // Operator() overloading
    bool operator()(const pair<int, int>& p1,
                    const pair<int, int>& p2)
    {
        // new definition
        if(p1.second>p2.second) return true;
        else if(p1.second == p2.second) return p1.first<p2.first;
        return false;
    }
};

set<pair<int,int>, comp> heson[MAXN];