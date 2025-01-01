/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    let n1 = s.length, n2 = t.length;
    if(n1 < n2) return "";

    const freq = new Map();
    for(const ch of t){
        freq.set(ch, (freq.get(ch) || 0) +1);
    }

    let st = -1, len = 1e9;
    let l = 0, r = 0, chars_from_t = 0;

    while(r < n1){
        if(freq.get(s[r]) > 0){
            chars_from_t++;
        }
        freq.set(s[r], (freq.get(s[r] || 0) - 1));

        while(chars_from_t == n2 && l<=r){
            if(len > r-l+1){
                len = r-l+1;
                st = l;
            }
            freq.set(s[l], freq.get(s[l])+1);
            if(freq.get(s[l]) > 0){
                chars_from_t--;
            }
            l++;
        }
        r++;
    }
    return st == -1 ? "": s.slice(st, st+len);
};