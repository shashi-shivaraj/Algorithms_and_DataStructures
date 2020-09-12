/*Given a pointer to the head of a linked list and a specific position, determine the data value at that position. Count backwards from the tail node.
The tail is at postion 0, its parent is at 1 and so on.
There are 3 elements with values 3, 2 and 1 (3 -> 2 -> 1). The element with position of 2 from tail contains 3.*/

int getNode(SinglyLinkedListNode* head, int positionFromTail) 
{
    int index = 0;

    //two pointer approach
    SinglyLinkedListNode* cur = head; //fast pointer moves through the list
    SinglyLinkedListNode* result = head; //slow pointer increments after fast pointer has moved positionFromTail moves 

    while(cur)
    {
        cur = cur->next;

        if(index++ > positionFromTail)
        {
            result = result->next;
        }
    }
    
    return result->data;
}