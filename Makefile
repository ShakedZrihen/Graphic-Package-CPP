CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
# OBJS += Button/Button.o
# OBJS += CheckList/CheckList.o
# OBJS += ComboBox/ComboBox.o
OBJS += Control/Control.o
OBJS += EventEngine/EventEngine.o
OBJS += Graphics/Graphics.o
# OBJS += IBorder/IBorder.o
# OBJS += IComposite/IComposite.o
# OBJS += IListener/IListener.o
# OBJS += IObserver/IObserver.o
OBJS += Label/Label.o
OBJS += FinalProject/Source.o
# OBJS += ListItem/ListItem.o
# OBJS += MessageBox/MessageBox.o
# OBJS += NumericBox/NumericBox.o
# OBJS += Panel/Panel.o
# OBJS += RadioBox/RadioBox.o
# OBJS += TextBox/TextBox.o

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe

