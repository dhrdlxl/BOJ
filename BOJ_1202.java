import java.io.*;
import java.util.*;

public class BOJ_1202 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Jewel[] jewels = new Jewel[N];
        TreeMap<Integer, Integer> bags = new TreeMap<>();

        for(int index = 0; index < N; index++)
        {
            st = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            jewels[index] = new Jewel(weight, cost);
        }

        for(int index = 0; index < K; index++)
        {
            int bag = Integer.parseInt(br.readLine());
            int count = 1;
            if(bags.containsKey(bag))
            {
               count = bags.get(bag) + 1; 
            }
            bags.put(bag, count);
        }

        Arrays.sort(jewels);

        long answer = 0;
        for(int index = 0; index < N; index++)
        {
            if(findBag(jewels[index].weight, bags))
            {
                answer+= jewels[index].cost;
            }
        }

        System.out.println(answer);
        return;
    }
    private static boolean findBag(int weight, TreeMap<Integer, Integer> bags)
    {
        Map.Entry<Integer, Integer> it = bags.ceilingEntry(weight);//weight 이상의 값
        
        if(it != null)
        {
            int key = it.getKey();
            int bagCount = it.getValue() - 1;
            if(bagCount == 0)
            {
                bags.remove(key);
            }
            else
            {
                bags.put(key, bagCount);
            }
            return true;
        }

        return false;
    }

    private static class Jewel implements Comparable<Jewel>
    {
        public int weight;
        public int cost;
        Jewel(int weight, int cost)
        {
            this.weight = weight;
            this.cost = cost;
        }
        public int compareTo(Jewel jewel)
        {
            return jewel.cost - this.cost;
        }
    }
}