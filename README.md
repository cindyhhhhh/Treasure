# Treasure

Problem Description:

One day, YP and BB found an ancient map showing the information of an underground world in the ADA kingdom. The underground world contains N underground cities connected via M directed roads, where the i-th directed road connects the city ui to the city vi, indicating that people can travel from ui to vi via this road.
Moreover, there are treasures everywhere in the underground world: the i-th city has si units of treasures and the j-th road has wj units of treasures.
As adventurers, YP and BB carry a bag with unlimited capacity to the underground world and want to pick up as many treasures as possible. They can start their journey at any city, visit an unlimited number of cities and roads, and go back to the ADA Kingdom via a spaceship at any city. Note that they always travel together. Once they visit a city or a road, they automatically pick up all treasures in the city or on the road; there will be no treasure if they visit the same city or the same road again.
Please write a program to help YP and BB compute the maximum units of treasures they can get.


Input:

The first line of the input contains two integers N and M indicating the number of underground cities and roads in the underground world, respectively.
The next line contains N space-separated integers s1, s2, . . . , sN , where the i-th integer indicates the units of treasures in the city i.
In the next M lines, each line contains three integers ui,vi,wi, indicating the road i connecting the city ui to vi with wi treasures.

• 1≤N ≤5×105
• 0≤M ≤5×105
• 1≤ui,vi ≤N,ui ̸=vi
• 0≤si ≤10^9 
• 0≤wi ≤10^9


Output:

Output an integer indicating the maximum units of treasure that YP and BB can collect in one line.

