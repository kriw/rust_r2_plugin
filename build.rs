extern crate cc;

fn main() {
    cc::Build::new()
        .file("src/core_pdd.c")
        .include("src")
        .include("/usr/include/libr")
        .include("/usr/include/capstone")
        .shared_flag(true)
        .compile("yo");
}
