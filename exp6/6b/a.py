x = [3,-1,0,1,3,2,0,1,2,1]
h = [1,1,1]
N = 5                 
xn = len(h) - 1
def circular_convolution(x_block, h):
    
    """ Computes circular convolution theorem using the fft """
    ## Padding
    # Appends zeroes in the begining of h to equal h_padded and block_len sizes
    h_padded = list(h)
    h_padded.extend([0] * (len(x_block)-len(h)))
    
    # From circular convolution theorem
    x_convolved = np.real(np.fft.ifft(np.fft.fft(x_block) * np.fft.fft(h_padded)))
    return x_convolved
    
    
def xn_save_convolution():
    """ Apply the filter defined by impulse response h over the long signal x using the xn-save method """
    
    if N == 0:
        print("Please set block size before applying convolution")
    
    # In the beginning there is no past block to xn from, so the first M-1 positions are set to zero
    x_padded = list(x)
    x_padded = [0]*(len(h) - 1) + x_padded
    
    # Defines convolution result
    y = []
    
    # loop over x len(h) steps at time, creating a xn of M-1 positions
    for i in range(0, len(x_padded), len(h)):
        ## Define x block
        # Covers the border case of the last block not being N-sized by appending N - (Len(x_padded) - i) zeroes to it
        if len(x_padded) - i < N:
            x_block = x_padded[i : len(x_padded)]
            x_block.extend([0] * (N - (len(x_padded) - i)))
            
        # For all other blocks, simply copy x_padded from i to i+N-1
        else:
            x_block = x_padded[i : i +N]
        
        # The partial result for a given block is the circular convolution between the signal block and filter impulse response 
        y_local = circular_convolution(x_block, h)
        print("X_block, y_local")
        print(x_block)
        print(y_local)
        
        # Keeps only values unnafected by the filter delay of circular convolution, achieving similar result as the linear convolution
        y.extend(y_local[len(h) - 1:])
    
    return y