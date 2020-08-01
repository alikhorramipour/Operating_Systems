public class Process {
    public int pid;
    public double burstTime;
    public double waitingTime;
    public double turnaroundTime;
    public Process(int pid, double burstTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        if (pid == 0) {
            waitingTime = 0;
            this.turnaroundTime = this.burstTime;
        }

    }
}
