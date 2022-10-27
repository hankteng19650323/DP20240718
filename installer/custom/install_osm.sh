# OSM Installation instructions:
# https://wiki.openstreetmap.org/wiki/Overpass_API/Installation

# Install expat. All other needed libraries are already installed.
# g++ make expat libexpat1-dev zlib1g-dev
#sudo apt-get update
#sudo apt-get install expat

# Add required path variables to environment
export OSM_DIR=/data/media/0/osm/
export TICI=${OSM_DIR}/0.7.57
export EON=${OSM_DIR}/0.7.56
export SOURCE_FILE_ROOT=osm-3s_v0.7.57
export GZ_FILE=${SOURCE_FILE_ROOT}.tar.xz
# export DB_DIR=/data/osm/db/

# Download and extract overpass library
cd /data/media/0/
if [ ! -d /data/media/0/osm ]; then
  mkdir osm
fi
cd /data/media/0/osm
#wget http://dev.overpass-api.de/releases/$GZ_FILE
cp -f /data/openpilot/selfdrive/mapd/assets/$GZ_FILE .
tar -vxf $GZ_FILE

# Configure and install overpass
#cd $(ls | grep $SOURCE_FILE_ROOT\.[0-9]*)
#cd osm-3s_v0.7.56
#./configure CXXFLAGS="-O2" --prefix=$EXEC_DIR
#make install

# Remove source files after installation
#cd ..
if [ -f /TICI ]; then
  if [ -d ${TICI} ]; then
    rm -rf ${TICI}
  fi
else
  if [ -d ${EON} ]; then
    rm -rf ${EON}
  fi
fi

if [ -f /TICI ]; then
mv osm-3s_v0.7.57 v0.7.57
else
mv osm-3s_v0.7.56 v0.7.56
fi


# Remove compressed overpass api
rm -rf $GZ_FILE
