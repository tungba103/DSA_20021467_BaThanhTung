public static class MyTextEditor {
    Stack<Object> history = new Stack<>();
    Stack<Character> text = new Stack<>();
    public void append(String str) {
        for (int i = 0; i < str.length(); i++) {
            text.push(str.charAt(i));
        }
        history.push(str.length());
    }

    public void delete(int k) {
        Stack<Character> undo = new Stack<>();
        for(int i = 0; i < k; i++) {
            undo.add(text.pop());
        }
        history.add(undo);
    }

    public char get(int k) {
        return text.get(k - 1);
    }

    public void undo() {
        Object o = history.pop();
        if (o instanceof Integer) {
            for(int i = 0; i < (Integer) o; i++) {
                text.pop();
            }
        } else {
            Stack<Character> undo = (Stack<Character>) o;
            while (!undo.isEmpty()) {
                text.add(undo.pop());
            }
        }
    }
}