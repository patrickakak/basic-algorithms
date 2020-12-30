static final int ALPHABET_SIZE = 256;

static class TrieNode {
  TrieNode[] children = new TrieNode[ALPHABET_SIZE];
  boolean isEndOfWord = false;
  TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
      children[i] = null;
  }
}
