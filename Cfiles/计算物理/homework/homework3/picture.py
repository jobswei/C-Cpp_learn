
import matplotlib.pyplot as plt

pi_lis=[]
with open("D://About_coding/Cfiles/计算物理/homework/homework3/pi array.txt","r") as fp:
    s=fp.read()
    pi_lis=s.split("\n")
    pi_lis.pop()
pi_lis=[float(i) for i in pi_lis]

# print(pi_lis)
plt.figure()
plt.plot(pi_lis)
plt.plot([0,len(pi_lis)],[3.14159,3.14159],'--')
plt.yticks([3,3.14])
plt.xlabel("n")
plt.ylabel("pi")
plt.savefig("D://About_coding/Cfiles/计算物理/homework/homework3/pi.jpg")
plt.show()