#include <iostream>
#include <string>
#include <vector>

struct RenderJob {
    int frameId;
    int estimatedRenderTime;
    int priority;
    std::string status;
};

void printAllJobs(const std::vector<RenderJob>& jobs);
int findLongestJob(const std::vector<RenderJob>& jobs);
void updateStatus(std::vector<RenderJob>& jobs, int num, std::string status);

int main() {
    std::vector<RenderJob> jobs = {
        {1, 150, 2, "pending"},
        {2, 600, 1, "pending"},
        {3, 300, 3, "pending"},
        {4, 900, 2, "pending"},
        {5, 450, 1, "pending"}
    };

    // Print all jobs
    printAllJobs(jobs);

    std::cout << "Longest frame: " << findLongestJob(jobs) << "\n";

    updateStatus(jobs, 3, "completed");

    printAllJobs(jobs);
}

void printAllJobs(const std::vector<RenderJob>& jobs) {
    // Print all jobs again
    for (const RenderJob& job: jobs) {
        std::cout << "frame: " << job.frameId << " Rendering Time: " << job.estimatedRenderTime << " priority: " << job.priority << " status " << job.status;
    }
}

int findLongestJob(const std::vector<RenderJob>& jobs) {
    int longestFrameId = jobs[0].frameId;
    int longestRenderTime = jobs[0].estimatedRenderTime;

    for (const RenderJob& job : jobs) {
        if (job.estimatedRenderTime > longestRenderTime) {
            longestRenderTime = job.estimatedRenderTime;
            longestFrameId = job.frameId;
        }
    }
    return longestFrameId;
}

void updateStatus(std::vector<RenderJob>& jobs, int num, std::string status) {
    for (RenderJob& job : jobs) {
        if (job.frameId == num) {
            job.status = status;
        }
    }
}