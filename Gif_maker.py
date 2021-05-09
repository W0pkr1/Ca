
#%%
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

cfg = np.loadtxt("cfg.txt")

def save_anim(h,num):
    mD = h.reshape(int(cfg[0]+1),int(cfg[1]),int(cfg[2]))
    fig = plt.figure(figsize=(10,10))
    plt.title("Conway", fontsize = 20)
    im = plt.imshow(mD[0])
    plt.show()

    def animate(i):
        im.set_array(mD[i])
        return [im]

    anim = animation.FuncAnimation(fig,animate,frames = int(cfg[0]+1) ,interval = 1000,)
    anim.save("vids/Cw_contour_"+str(num)+ ".gif",writer='pillow')


handler1 = np.loadtxt('data/conway.txt')


save_anim(handler1,1)
# %%
