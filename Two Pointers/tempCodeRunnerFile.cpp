       while(j < n and arr[i] == arr[j]) {
            j++;
        }
        
        if(j >= n) return i + 1;
        i++;
        arr[i] = arr[j];
        j++;
    }

    return i + 1;