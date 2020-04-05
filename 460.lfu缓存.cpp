/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 *
 * https://leetcode-cn.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (34.46%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 21.2K
 * Testcase Example:
 '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
 *
 * get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
 * put(key, value) -
 * 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
 *
 * 一个项目的使用次数就是该项目被插入后对其调用 get 和 put
 函数的次数之和。使用次数会在对应项目被移除后置为 0。
 *
 * 进阶：
 * 你是否可以在 O(1) 时间复杂度内执行两项操作？
 *
 * 示例：
 *
 * LFUCache cache = new LFUCache( 2 capacity (缓存容量) );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回 1
 * cache.put(3, 3);    // 去除 key 2
 * cache.get(2);       // 返回 -1 (未找到key 2)
 * cache.get(3);       // 返回 3
 * cache.put(4, 4);    // 去除 key 1
 * cache.get(1);       // 返回 -1 (未找到 key 1)
 * cache.get(3);       // 返回 3
 * cache.get(4);       // 返回 4
 *
 */

// @lc code=start
#include <algorithm>
#include <list>
#include <memory>
#include <unordered_map>
using namespace std;

struct node {
  int key;
  int value;
  int freq;
  node(int k, int v) {
    key = k;
    value = v;
    freq = 1;
  }
};

class LFUCache {
 private:
  int min_freq;
  int cap;
  int sz;
  unordered_map<int, list<node>::iterator> key_table;
  unordered_map<int, list<node>> freq_table;

 public:
  LFUCache(int capacity) {
    min_freq = 1;
    cap = capacity;
  }

  int get(int key) {
    if (key_table.count(key)) {
      auto it = key_table[key];
      auto tmp = *it;
      freq_table[tmp.freq].erase(it);
      if (freq_table[tmp.freq].size() == 0) {
        freq_table.erase(tmp.freq);
        if (min_freq == tmp.freq) ++min_freq;
      }
      ++tmp.freq;
      freq_table[tmp.freq].push_front(tmp);
      key_table[key] = freq_table[tmp.freq].begin();
      return tmp.value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (cap == 0) return;
    if (key_table.count(key)) {
      get(key);
      key_table[key]->value = value;
      return;
    } else if (key_table.size() == cap) {
      auto tmp = freq_table[min_freq].back();
      key_table.erase(tmp.key);
      freq_table[min_freq].pop_back();
      if (freq_table[min_freq].size() == 0) freq_table.erase(min_freq);
    }
    min_freq = 1;
    freq_table[min_freq].emplace_front(key, value);
    key_table.insert({key, freq_table[min_freq].begin()});
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
