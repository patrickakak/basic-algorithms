class TrieNode:

    # Trie node class
    def __init__(self):
        self.children = [None] * ALPHABET_SIZE
        
        # isEndOfWord is True if node represent
        # the end of the word
        self.isEndOfWord = False
        
