/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (45.38%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    32.5K
 * Total Submissions: 71.4K
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用)
 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 *
 * 获取数据 get(key) - 如果密钥 (key)
 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 *
 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 *
 * 进阶:
 *
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 *
 * 示例:
 *
 * LRUCache cache = new LRUCache( 2  缓存容量  );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class LRUCache {
 public:
  LRUCache(int cap) : capacity(cap) {}

  int get(int key) {
    if (data.count(key)) {
      update_history_chain(key);
      return data[key];
    }
    return -1;
  }

  void put(int key, int value) {
    if (!data.count(key)) {
      if (data.size() == capacity) {
        auto it = get_lru();
        data.erase(*it);
        lru_map.erase(*it);
        history_chain.pop_front();
      }
      data.insert({key, value});
      history_chain.push_back(key);
      lru_map.insert({key, --history_chain.end()});
    } else {
      data[key] = value;
      update_history_chain(key);
    }
  }

 private:
  int capacity;
  list<int> history_chain;
  // <key, iter>
  unordered_map<int, list<int>::iterator> lru_map;
  // <Key, value>
  unordered_map<int, int> data;
  // void display_chain() {
  //   for (auto i : history_chain) cout << i << " ";
  //   cout << endl;
  // }
  void update_history_chain(int key) {
    auto it = lru_map[key];
    history_chain.erase(it);
    history_chain.push_back(key);
    lru_map[key] = --history_chain.end();
  }

  list<int>::iterator get_lru() { return history_chain.begin(); }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
