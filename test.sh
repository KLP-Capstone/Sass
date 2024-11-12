if [ $# -eq 0 ] ; then
  cd ./libsass_dir &&
  make &&
  cd ../sassc_dir &&
  SASS_LIBSASS_PATH=../libsass_dir make &&
  cd .. &&
  time ./sassc_dir/bin/sassc input.scss output.css &&
  rm ./sassc_dir/bin/sassc
elif [ $# -eq 1 ] ; then
  cd ./libsass_dir &&
  make &&
  cd ../sassc_dir &&
  SASS_LIBSASS_PATH=../libsass_dir make &&
  cd .. &&
  case $1 in
  *".scss") time ./sassc_dir/bin/sassc $1 output.css
  ;;
  *".css") time ./sassc_dir/bin/sassc input.scss $1
  ;;
  *".sass") time ./sassc_dir_bin/sassc $1 output.css &&
            echo "Warning : .sass file proccessing may not work"
  ;;
  *) echo "unsupported file type (use .scss and .css only)"
  esac &&
  rm ./sassc_dir/bin/sassc
elif [ $# -eq 2 ] ; then
  cd ./libsass_dir &&
  make &&
  cd ../sassc_dir &&
  SASS_LIBSASS_PATH=../libsass_dir make &&
  cd .. &&
  time ./sassc_dir/bin/sassc $1 $2 &&
  rm ./sassc_dir/bin/sassc
else
  echo "Too many Arguments (0 ~ 2 arguments allowed)"
fi
