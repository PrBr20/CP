auto Test = [&](long long x) {
      int cnt = 0;
      for (int v : a) {
        long long u = llround(sqrtl(v + x));
        if (u * u == v + x) {
          cnt += 1;
        }
      }
      ans = max(ans, cnt);
    };