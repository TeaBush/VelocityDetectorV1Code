The velocity detector detailed in this guide was developed as a prototype to replace the original that came with the Instron Dynatup 9200. As it is open-source in nature, anyone can easily modify and expand on it for further use. 

The detector uses an IR sensor to detect when an object passes through the beam it emits. When an object, such as the flag of the Instron drop tower, passes through the beam, the microcontroller begins counting elapsed time until that part of the flag is no longer detected. It then records this total time, and divides the length of the flag by it to obtain the velocity of the object. 