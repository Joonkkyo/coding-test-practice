class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        row, col = len(image), len(image[0])
        prev_color = image[sr][sc]
        
        def dfs(y, x):
            if not (0 <= x < col and 0 <= y < row) or  \
                    image[y][x] == newColor or image[y][x] != prev_color:
                return

            image[y][x] = newColor
            dfs(y - 1, x)
            dfs(y + 1, x)
            dfs(y, x - 1)
            dfs(y, x + 1)

        dfs(sr, sc)
        return image
