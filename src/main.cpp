#include <iostream>
#include <vector>

enum class JobStatus {
    Pending,
    Running,
    Completed,
    Failed
};

std::string statusToString(JobStatus status) {
    switch (status) {
        case JobStatus::Pending:
            return "Pending";

        case JobStatus::Running:
            return "Running";

        case JobStatus::Completed:
            return "Completed";

        case JobStatus::Failed:
            return "Failed";
    }

    return "Unknown";
}

// per job
struct RenderJob {
    int frameId;
    int estimatedRenderTime;
    int priority;
    JobStatus status;
};

// all jobs
class JobManager {
private:
    std::vector<RenderJob> jobs;
    int nextJobId = 1;

public:
    int submitJob(int renderTime, int priority) {
        // TODO:
        // Create a new RenderJob
        RenderJob newJob = {nextJobId, renderTime, priority, JobStatus::Pending};
        jobs.push_back(newJob);

        int assignedId = nextJobId;
        nextJobId++;
        return assignedId;
    }

    int getJobCount() const {
        // TODO
        return jobs.size();
    }

    void printAllJobs() const {
        // TODO
        // Print frame ID, render time and priority
        // Also print a readable status
        for (const RenderJob& job: jobs) {
            std::string status = statusToString(job.status);

            std::cout << " frame: " << job.frameId << " Rendering Time: " << job.estimatedRenderTime << " priority: " << job.priority << " status " << status << "\n";
        }
    }

    bool updateStatus(int frameId, JobStatus newStatus) {
        // TODO
        // Find the matching job
        // Update its status
        // Return true if found, false otherwise
        for (RenderJob& job : jobs) {
            if (job.frameId == frameId) {
                job.status = newStatus;
                return true;
            }
        }
        return false;
    }
};

int main() {
    JobManager manager;

    int firstId = manager.submitJob(150, 2);
    manager.submitJob(600, 1);
    manager.submitJob(300, 3);

    manager.printAllJobs();

    manager.updateStatus(firstId, JobStatus::Completed);

    std::cout << "\nAfter updating:\n";
    manager.printAllJobs();

    std::cout << "\nTotal jobs: "
              << manager.getJobCount() << "\n";

    return 0;
}
