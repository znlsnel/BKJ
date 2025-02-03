public class Solution {
        public int LargestRectangleArea(int[] heights)
        {

                Stack<int> stack = new Stack<int>();
                int maxArea = 0;
                int n = heights.Length;

                for (int i = 0; i < n; i++)
                {
                        while (stack.Count > 0 && heights[i] < heights[stack.Peek()])
                        {
                                int h = stack.Pop();
                                int width;

                                if (stack.Count == 0)
                                        width = i;
                                else
                                        width = i - stack.Peek() - 1;

                                int area = heights[h] * width;
                                maxArea = Math.Max(maxArea, area);
                        }
                        stack.Push(i);
                }

                while (stack.Count > 0)
                {
                        int h = stack.Pop();
                        int width;

                        if (stack.Count == 0)
                                width = n;
                        else
                                width = n - stack.Peek() - 1;

                        int area = heights[h] * width;
                        maxArea = Math.Max(maxArea, area);

                }


                return maxArea;
        }
}