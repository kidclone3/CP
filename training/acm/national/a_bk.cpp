// printPair(st);
    // while(!st.empty()) {
    //     // Lay dau cuoi.
    //     auto it1 = st.begin();
    //     auto it2 = prev(st.end());
    //     int it1_f, it1_s, it2_f, it2_s;
    //     // Lay gia tri cua iter.
    //     tie(it1_f, it1_s) = *it1;
    //     tie(it2_f, it2_s) = *it2;
    //     // check xem 1 minh cai dau co' can dc ko.
    //     if(it1_f >= n) {
    //         pos[it1->second].push_back({p, n});
    //         it1_f -= n;
    //         st.erase(it1);
    //         if (it1_f > 0) {
    //             st.insert({it1_f, it1_s});
    //         }
    //         continue;
    //     }
    //     // check xem neu con 1 ptu thi se nhu nao.
    //     if (it1 == it2) {
    //         if (it1_f % n != 0) {
    //             ok = false;
    //             break;
    //         } else {
    //             it1_f -= n;
    //             pos[it1_s].push_back({p, n});
    //             st.erase(it1);
    //             if (it1_f > 0) {
    //                 st.insert({it1_f, it1_s});
    //             }
    //         }
    //         continue;
    //     }
    //     // Dkien: neu min + max < n => tach.
    //     if (it1_f + it2_f < n)  {
    //         ok = false;
    //         break;
    //     }
    //     st.erase(it1);
    //     st.erase(it2);
    //     it2_f -= n - it1_f;
    //     pos[it1_s].push_back({p, it1_f});
    //     pos[it2_s].push_back({p, n - it1_f});
    //     if (it2_f > 0)
    //         st.insert({it2_f, it2_s});
    //     p++;
    // }
    // sort(all(st));
    // cout << ok;
    // printPair(st);
    // EACH(it, pos) if (!it.second.empty()) printPair()
