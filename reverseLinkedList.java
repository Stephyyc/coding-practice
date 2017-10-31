import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 *
 * 
 */

class Node {
  public Node next;
  public int data;
}

class Solution {
  
  public static Node reverseList(Node head) {
    
    Node temp; 
    Node previousNode = null; 
    Node currentNode = head;
    
    while (currentNode != null) {
      temp = currentNode.next; 
      currentNode.next = previousNode;
      previousNode = currentNode;
      currentNode = temp;
         
    }
    
    return previousNode;
    
    
  }
  
  public static void main(String[] args) {
    Node firstNode = new Node();
    Node secondNode = new Node();
    Node thirdNode = new Node();
    
    firstNode.data = 1;
    secondNode.data = 2;
    thirdNode.data = 3;
    
    firstNode.next = secondNode;
    secondNode.next = thirdNode;
    thirdNode.next = null; 
    
    Node current = reverseList(firstNode);
    
    while (current != null) {
      
      System.out.println(current.data);
      current = current.next;
    }
    
    
  }
}