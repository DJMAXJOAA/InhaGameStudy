const lengthOfLongestSubstring = function(s) {
    let subStr = "";
    let maxLength = 0;

    for (let i = 0; i < s.length; i++) {
        if (subStr.includes(s[i])) {
            subStr = subStr.slice(subStr.indexOf(s[i]) + 1);
        }
        subStr += s[i];
        if (maxLength < subStr.length) {
            maxLength = subStr.length;
        }
    }
    return maxLength;
};