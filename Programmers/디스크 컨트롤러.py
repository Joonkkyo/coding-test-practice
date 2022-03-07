import heapq

def solution(jobs):
    heap = []
    jobs.sort(key=lambda x : x[0])
    start, end = -1, 0
    comp_jobs, total_time = 0, 0
    
    while comp_jobs < len(jobs):
        for job in jobs: 
            if start < job[0] <= end:
                heapq.heappush(heap, [job[1], job[0]])
                
        if heap:
            tmp_job = heapq.heappop(heap)
            start = end
            end += tmp_job[0]
            total_time += end - tmp_job[1]
            comp_jobs += 1
            
        else:
            end += 1
                
    answer = int(total_time / len(jobs))
    return answer
