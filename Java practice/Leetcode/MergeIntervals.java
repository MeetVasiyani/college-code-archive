Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        Stack<Integer> stack = new Stack<>();
        List<int[]> list = new ArrayList<>();

        stack.push(intervals[0][0]);
        stack.push(intervals[0][1]);

        int n = intervals.length;
        for(int i = 1; i < n; i++){
            int prevEnd = stack.peek();

            if (prevEnd >= intervals[i][0]) {
                stack.pop();
                stack.push(Math.max(prevEnd, intervals[i][1]));
            }
            else {
                int[] temp = new int[2];
                temp[1] = stack.pop();
                temp[0] = stack.pop();
                list.add(temp);

                stack.push(intervals[i][0]);
                stack.push(intervals[i][1]);
            }
        }
        
        int[] last = new int[2];
        last[1] = stack.pop();
        last[0] = stack.pop();
        list.add(last);

        return list.toArray(new int[list.size()][]);