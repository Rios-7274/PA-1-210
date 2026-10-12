1. Why does concat only need to work between two lists of the same representation? What would
you have to do differently, or what would go wrong, if you tried to make it work between a
LinkedList and an ArrayList?

concat only needs to work between two list of the same represenation because the only way to actuially 
change the list type is to manually swap the line inside makeList(). Trying to make it work between a 
LinkedList and an ArrayList would require a different implementation of concat and a way to select between 
the two list types at runtime. Additionally, this may require a method of converting between the two list 
types that would be challenging to implement because they handle data differently. 

2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
and explain why losing track of any one of them mid-loop corrupts the list.

The three pointers that need to be alive at once are the current node (starts at head), the previious node `prev`
(starts as nullptr), and the next node (starts as nullptr). Losing track of any one of them mid-loop 
corrupts the list, without 'prev' we wont be able to relink backwards, without `current` we wont know which node to
process and move `prev` to, and without `next` we wont know which node to move `current` to after we relink.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
position in each, and what does your implementation do if a caller passes a position outside
it?

The valid range for position in addAnywhere is 0 to size inclusive because 0 always represents the front og the list and size
is the valid position/index after the last element. In deleteAnywhere its 0 to size -1 inclusive, size -1 because thats the 
last position of an element that isn't already empty. If a caller passes a position outside of range, my implementation 
will print an "invalid position" message and return without making any changes to the list.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
and deleteFront never needed to? What would change about concat’s performance if
LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
if you added one back?

In LinkedList::concat, you need to walk to the end of the list first to reach the last node, this node will link to the head of 
the other List. addFront and deleteFront never need to walk past the head since they only work with the very first node. 
If LinkedList tracked a tail pointer, the time complexity of concat would imporve to 0(1) from O(n), and the tail pointer
would need to be updated in concat and all the current add and delete methods. NOTE: My current LinkedList does have an implemented
tail pointer as I found it more logically accessible to work with.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
has to shift and in which direction, and why shifting in the wrong direction would overwrite
data you still need.

In the Arraylist implementation of addAnywhere, all elements from the position to the end of the list has to shift to
the right. This makes room for the element to be added. Shifting in the wrong direction would overwrite the data currently
at the position we want to add to, both during the shift and when we add the new element, resulting in two positions of needed
data being lost.

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
play, and explain what would visibly break in the game if that call were missing.

line 42 in main.cpp is where a reverse card changes the direction of play. Visibly, if that call were missing, the game continues to 
play in the same order, which is now the wrong direction and breaks the rules of the reverse card.