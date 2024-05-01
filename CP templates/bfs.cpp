  
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(ll i, ll j) { return i >= 1 && i <= n && j >= 1 && j <= m; }

  queue> que;
    bool visited[n + 5][m + 5];
    memset(visited, false, sizeof(visited));
    if (arr[n][m] == '.') {
      que.push({n, m});
      visited[n][m] = true;
    }
    while (!que.empty()) {
      pair curr = que.front();
      que.pop();
      for (ll k = 0; k < 4; k++) {
        ll ni = curr.first + dir[k][0];
        ll nj = curr.second + dir[k][1];
        if (valid(ni, nj) && !visited[ni][nj]) {
          que.push({ni, nj});
          visited[ni][nj] = true;
        }
      }
    }