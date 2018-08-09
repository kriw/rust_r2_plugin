use std::ffi::CStr;
use std::os::raw::c_void;

// fn to_safe_string() -> String {
//     unsafe { CStr::from_ptr(my_string()).to_string_lossy().into_owned() }
// }

#[no_mangle]
pub extern "C" fn cmd(_user: *mut c_void, _input: &CStr) {
    println!("cmd");
}

#[no_mangle]
pub extern "C" fn init(_user: *mut c_void, _input: &CStr) {
    println!("init");
}
