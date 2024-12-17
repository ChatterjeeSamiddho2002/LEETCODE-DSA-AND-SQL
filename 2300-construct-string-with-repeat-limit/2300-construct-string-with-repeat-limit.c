char* repeatLimitedString(char* s, int repeatLimit) {
    // populates hash table of characters and get string size O(n)
  int hash[26] = {0}, size = 0;
  while (s[size]) {
    ++hash['z' - s[size]];
    ++size;
  }
  
  // sorts the string so lexicographically largest O(n)
  char* temp = s;
  for (int i = 0; i < 26; ++i) {
    while (hash[i]) {
      *temp = 'z' - i;
      ++temp;
      --hash[i];
    }
  }

  // moves characters that are repeated too many times O(n + n)
  int repeated = 0, next = 0;
  for (int i = 1; i < size; ++i) {
    // keeps track of number of letters repeated
    (s[i - 1] == s[i]) ? (++repeated) : (repeated = 0);
    if (repeated == repeatLimit) {
      // finds the next character that is less than the current charcter
      while (next < size && s[i] <= s[next]) ++next;
      // swaps characters
      char temp = s[i];
      s[i] = s[next];
      s[next] = temp;
    }
  }
  return s;
}