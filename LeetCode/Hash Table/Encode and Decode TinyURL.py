class Codec:
    def __init__(self):
        self.encodeMap = {}
        self.decodeMap = {}
        
        
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        encode_key = longUrl.split('/')[-1]
        encode_value = '1'
        shortUrl = "http://tinyurl.com/" + encode_value
        self.encodeMap[longUrl] = shortUrl
        self.decodeMap[shortUrl] = longUrl
        
        return self.encodeMap[longUrl]
    
    
    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.decodeMap[shortUrl]        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
