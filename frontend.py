import ttkbootstrap as ttk
from ttkbootstrap.constants import *
import subprocess

def recommend_crops():
    soil = soil_type.get()
    ph = ph_value.get()
    temp = temp_value.get()

    result_label.config(text="", foreground="black")

    if not soil or not ph or not temp:
        result_label.config(text="Please enter all values: soil type, pH, and temperature.", foreground="red")
        return

    try:
        float(ph)
        float(temp)
    except ValueError:
        result_label.config(text="pH and Temperature must be numeric values.", foreground="red")
        return

    try:
        result = subprocess.run(
            ["backend.exe", soil, ph, temp],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        if result.returncode == 0:
            result_window = ttk.Toplevel()
            result_window.title("RESULT")
            result_window.geometry("300x200")
            result_output = ttk.Label(result_window, text=result.stdout.strip(), font=("Helvetica", 14))
            result_output.pack()
        else:
            result_label.config(text=result.stderr.strip(), foreground="red")
    except FileNotFoundError:
        result_label.config(text="Backend executable not found.", foreground="red")
    except Exception as e:
        result_label.config(text=f"Unexpected error: {str(e)}", foreground="red")

root = ttk.Window(themename="superhero")
root.geometry("800x500")
root.title("Crop Recommender")

soil_type = ttk.StringVar(root)
soil_type.set("Loamy")

ttk.Label(root, text="Soil Type:").pack()
soil_type_menu = ttk.OptionMenu(root, soil_type, 'Loamy', 'Sandy', 'Clay', 'Silty', 'Peaty')
soil_type_menu.pack(pady=10)

ttk.Label(root, text="Soil pH:").pack()
ph_value = ttk.Entry(root)
ph_value.pack(pady=10)

ttk.Label(root, text="Temperature (°C):").pack()
temp_value = ttk.Entry(root)
temp_value.pack(pady=10)

recommend_button = ttk.Button(root, text="Recommend Crops", command=recommend_crops, bootstyle=WARNING)
recommend_button.pack(pady=10)

result_label = ttk.Label(root, text="", font=("Helvetica", 12))
result_label.pack(pady=20)

root.mainloop()
