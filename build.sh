build_dir="build"
mode="BUILD_ONLY"

if [ "$1" ]; then
    if [ "$1" = "test" ]; then
        mode="TEST";
    elif [ "$1" = "run" ]; then
        mode="RUN";
    else
        echo "ERROR: Unknown option!";
        exit 1;
    fi
fi

mkdir -p $build_dir;
cd $build_dir;
cmake .. && make all;
if [ $? -ne 0 ]; then
    exit 1;
fi

if [ "$mode" = "BUILD_ONLY" ]; then
    exit 0;
elif [ "$mode" = "TEST" ]; then
    ./test/TestSort;
elif [ "$mode" = "RUN" ]; then
    ./src/Main;
fi

cd -;
