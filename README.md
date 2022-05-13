# 6.172

## Devenv Setup Instructions


1. Build devenv image locally
   `docker build -t 6172/devenv .`
   

2. (For Mac) Download XQuartz if you havent
   - In the XQuartz interface, go to the `Preferences > Security`tab and enable "Allow connections from network clients".
   - In the xterm shell (which opens when you open XQuartz), run:
     `xhost + localhost`
   
   
3. Create container with docker X11 passthrough
   `docker run -td -e DISPLAY=host.docker.internal:0 6172/devenv`
   
   Or with synced volume (for automatically syncing code changes into container):
   `docker run -td -e DISPLAY=host.docker.internal:0 -v ~/6.172:/6.172/ 6172/devenv`

   
4. Profit? Can do cool stuff like:
   - run any code using graphics in the container (e.g. project2) and forward it through localhost
     - e.g. test it out by exec-ing into the built container and trying `xclock` or `./screensaver -g 100` in the project2 directory once compiled
   - sync code changed in this repo  automatically through the mounted volume, test quickly on the devenv container


