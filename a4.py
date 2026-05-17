import tkinter as tk

def chatbot_resp(user_msg):
    user_input = user_msg.lower()

    if user_input == "hello" or user_input == "hi":
        return "Hello! How can i help you?"
    elif "price" in user_input:
        return "our products range from Rs. 999"
    elif "bye" in user_input or "thank you" in user_input:
        return "Thank you for visiting"
    else:
        return "Sorry, I didn't understand that."

def send_msg():
    user_msg = entry.get()
    if user_msg=="":
        return
    chat_area.insert(tk.END, "You: "+user_msg+"\n")
    resp = chatbot_resp(user_msg)
    chat_area.insert(tk.END, "Bot: "+resp+"\n")
    entry.delete(0, tk.END)

root = tk.Tk()
root.title("Customer Support Chatbot\n")
root.geometry("800x800")
root.configure(bg="blue")

chat_area = tk.Text(root, height=30, width=60, bg="white", fg="black")
chat_area.pack(pady=10)

label = tk.Label(root, text="Enter your message", bg="blue")
label.pack()

entry = tk.Entry(root, width = 10, bg="white", fg="black", bd=3)
entry.pack(pady=10)

send_button = tk.Button(root, text="Send", command=send_msg, bg="blue", fg="white")
send_button.pack();

root.mainloop()