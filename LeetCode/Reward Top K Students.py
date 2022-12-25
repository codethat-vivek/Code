# Question Link - https://leetcode.com/problems/reward-top-k-students/

# Solution - 

class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        pos, neg = collections.Counter(positive_feedback), collections.Counter(negative_feedback)
        dt = collections.defaultdict(int)
        for idx, each in enumerate(report):
            for word in each.split(' '):
                if word in pos:
                    dt[student_id[idx]] += 3
                elif word in neg:
                    dt[student_id[idx]] -= 1
        
        x = sorted(dt.items(), key = lambda x : (-x[1], x[0]))[:k]
        return [e[0] for e in x]
