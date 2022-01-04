string gcdOfStrings(string str1, string str2) {
    if (str1 == str2)
        return str1;
    int gcd = __gcd((int)str1.size(), (int)str2.size());
    string combinedStr = str1 + str2;
    string result = str1.substr(0, gcd);
    //If result fully present in str1 return result
    while (combinedStr.size() > 0) {
        if (combinedStr.substr(0, gcd) != result)
            return "";
        combinedStr = combinedStr.substr(gcd);
    }
    if (combinedStr == "")
        return result;
    return "";
}