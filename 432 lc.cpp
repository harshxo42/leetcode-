#include <unordered_map>
#include <unordered_set>
#include <string>

class AllOne {
private:
    struct Bucket {
        int count;
        std::unordered_set<std::string> keys;
        Bucket* prev;
        Bucket* next;
        
        Bucket(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    
    Bucket* head;
    Bucket* tail;
    std::unordered_map<std::string, int> countMap;
    std::unordered_map<int, Bucket*> bucketMap;
    
    void addBucketAfter(Bucket* node, int count) {
        Bucket* newBucket = new Bucket(count);
        newBucket->prev = node;
        newBucket->next = node->next;
        node->next->prev = newBucket;
        node->next = newBucket;
        bucketMap[count] = newBucket;
    }
    
    void removeBucket(Bucket* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        bucketMap.erase(node->count);
        delete node;
    }
    
public:
    AllOne() {
        head = new Bucket(0);
        tail = new Bucket(0);
        head->next = tail;
        tail->prev = head;
    }
    
    ~AllOne() {
        Bucket* curr = head;
        while (curr) {
            Bucket* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    void inc(std::string key) {
        if (countMap.find(key) == countMap.end()) {
            // New key, add to count 1
            countMap[key] = 1;
            if (bucketMap.find(1) == bucketMap.end()) {
                addBucketAfter(head, 1);
            }
            bucketMap[1]->keys.insert(key);
        } else {
            // Existing key, move to next count
            int oldCount = countMap[key];
            int newCount = oldCount + 1;
            countMap[key] = newCount;
            
            // Remove from old bucket
            Bucket* oldBucket = bucketMap[oldCount];
            oldBucket->keys.erase(key);
            
            // Add to new bucket (create if doesn't exist)
            if (bucketMap.find(newCount) == bucketMap.end()) {
                addBucketAfter(oldBucket, newCount);
            }
            bucketMap[newCount]->keys.insert(key);
            
            // Remove old bucket if empty
            if (oldBucket->keys.empty()) {
                removeBucket(oldBucket);
            }
        }
    }
    
    void dec(std::string key) {
        int oldCount = countMap[key];
        int newCount = oldCount - 1;
        
        if (newCount == 0) {
            // Remove key completely
            countMap.erase(key);
            Bucket* oldBucket = bucketMap[oldCount];
            oldBucket->keys.erase(key);
            
            if (oldBucket->keys.empty()) {
                removeBucket(oldBucket);
            }
        } else {
            // Move to new bucket
            countMap[key] = newCount;
            Bucket* oldBucket = bucketMap[oldCount];
            oldBucket->keys.erase(key);
            
            // Add to new bucket (create if doesn't exist)
            if (bucketMap.find(newCount) == bucketMap.end()) {
                addBucketAfter(oldBucket->prev, newCount);
            }
            bucketMap[newCount]->keys.insert(key);
            
            // Remove old bucket if empty
            if (oldBucket->keys.empty()) {
                removeBucket(oldBucket);
            }
        }
    }
    
    std::string getMaxKey() {
        if (head->next == tail) {
            return "";
        }
        return *(bucketMap[tail->prev->count]->keys.begin());
    }
    
    std::string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(bucketMap[head->next->count]->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
