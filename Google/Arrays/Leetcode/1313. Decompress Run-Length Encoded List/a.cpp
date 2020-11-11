class Solution {
public:
    vector<int> decompressRLElist(vector<int>& a) {
        size_t aSize = a.size();
        vector<int> decompressed;
        
        for(size_t i = 0; i < aSize; i += 2){
            int frq = a[i];
            int val = a[i + 1];
            for(size_t j = 0; j < frq; j++){
                decompressed.push_back(val);
            }
        }
        
        return decompressed;
    }
};
