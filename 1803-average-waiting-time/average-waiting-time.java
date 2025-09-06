class Solution {
    public double averageWaitingTime(int[][] customers) {
       int idleTime = 1;
       long totalWaitingtime = 0;
        double n = customers.length;

        for(int customer[] : customers){
           if(idleTime <= customer[0]){
                idleTime = customer[0] + customer[1];
           }else{
                idleTime = idleTime + customer[1];
           }
           totalWaitingtime += idleTime - customer[0];
        }
        
        return totalWaitingtime / n;
    }
}