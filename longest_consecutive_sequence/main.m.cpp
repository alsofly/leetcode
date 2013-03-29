class Solution {
public:
   struct Item {
      Item(): hasNextLeft(false), hasNextRight(false), visited(false) {};
      bool hasNextLeft;
      bool hasNextRight;
      bool visited;
   };

   int longestConsecutive(vector<int> &num) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function

      int maxCon(1);

      // Create the doubleLinkedList for all the values
      map<int, Item> table;
      for ( vector<int>::const_iterator it = num.begin();
            it != num.end(); ++it )
      {
         Item item;
         map<int, Item>::iterator leftPos = table.find(*it - 1);
         map<int, Item>::iterator rightPos = table.find(*it + 1);

         if ( leftPos != table.end() )
         {
            (leftPos->second).hasNextRight = true;
            item.hasNextLeft = true;
         }

         if ( rightPos != table.end() )
         {
            (rightPos->second).hasNextLeft = true;
            item.hasNextRight = true;
         }

         table.insert(pair<int, Item>(*it, item));
      }

      for (map<int, Item>::iterator it = table.begin();
            it != table.end(); ++it )
      {
         if ( (it->second).visited == true ) continue;
         int len = find_length(it, table);
         if ( len > maxCon ) maxCon = len;
      }

      return maxCon;

   }

   int find_length(map<int, Item>::iterator curr, map<int, Item>& table)
   {
      // Go Left
      int total = 1;
      int currVal = curr->first;
      (curr->second).visited = true;
      while ( (curr->second).hasNextLeft == true )
      {
         curr = table.find(curr->first - 1);
         (curr->second).visited = true;
         total++;
      }

      // Go Right
      curr = table.find(currVal);
      while( (curr->second).hasNextRight == true )
      {
         curr = table.find(curr->first + 1);
         (curr->second).visited = true;
         total++;
      }

      return total;
   }
};
