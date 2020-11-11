char firstNotRepeatingCharacter(string s) {
    char ret = '_';
    unordered_map<char, int> frq;
    
    for(char c: s) {
        frq[c]++;
    }
    
    for(char c: s) {
        if(frq[c] == 1) {
            ret = c;
            break;
        }
    }
    
    return ret;
}
