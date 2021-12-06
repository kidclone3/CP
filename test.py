class Twitter:
    _follows =[]
    _usertweets = []
    def __init__(self, follows = [], usertweets = []):
        # self._follows = follows
        # self._usertweets = usertweets    
        pass 
 
    def postTweet(self, userId: int, tweetId: int) -> None:
        self._usertweets.append([tweetId, userId])
 
    def getNewsFeed(self, userId: int) -> List[int]:
        counter = 0
        ans = []
        print(len(self._usertweets))
        for i in range(len(self._usertweets)-1, -1, -1):
            if counter == 10:
                break
            if self._usertweets[i][1] == userId or [userId, self._usertweets[i][1]] in self._follows:
                # print(self.usertweets[i][0])
                ans.append(self._usertweets[i][0])
                # print(ans)
                counter += 1
        return ans
 
    def follow(self, followerId: int, followeeId: int) -> None:
        self._follows.append([followerId, followeeId])
 
    def unfollow(self, followerId: int, followeeId: int) -> None:
        self._follows.remove([followerId, followeeId])
 
 
# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)