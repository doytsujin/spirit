import core.corelib as corelib
import ctypes

### Load Library
_core = corelib.LoadCoreLibrary()


### Get Bounds
_Get_Bounds          = _core.Geometry_Get_Bounds
_Get_Bounds.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_int]
_Get_Bounds.restype  = None
def Get_Bounds(p_state, min, max, idx_image=-1, idx_chain=-1):
    vec3 = ctypes.c_float * 3
    _Get_Bounds(p_state, vec3(*min), vec3(*max), idx_image, idx_chain)

### Get Center
_Get_Center          = _core.Geometry_Get_Center
_Get_Center.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_int]
_Get_Center.restype  = None
def Get_Center(p_state, center, idx_image=-1, idx_chain=-1):
    vec3 = ctypes.c_float * 3
    _Get_Center(p_state, vec3(*center), idx_image, idx_chain)

### Get Basis vectors
_Get_Basis_Vectors          = _core.Geometry_Get_Basis_Vectors
_Get_Basis_Vectors.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_int]
_Get_Basis_Vectors.restype  = None
def Get_Basis_Vectors(p_state, a, b, c, idx_image=-1, idx_chain=-1):
    vec3 = ctypes.c_float * 3
    _Get_Basis_Vectors(p_state, vec3(*a), vec3(*b), vec3(*c), idx_image, idx_chain)

### Get N Cells
_Get_N_Cells          = _core.Geometry_Get_N_Cells
_Get_N_Cells.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_int]
_Get_N_Cells.restype  = None
def Get_N_Cells(p_state, na, nb, nc, idx_image=-1, idx_chain=-1):
    _Get_N_Cells(p_state, na, nb, nc, idx_image, idx_chain)

### Get Translation Vectors
_Get_Translation_Vectors          = _core.Geometry_Get_Translation_Vectors
_Get_Translation_Vectors.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_int]
_Get_Translation_Vectors.restype  = None
def Get_Translation_Vectors(p_state, ta, tb, tc, idx_image=-1, idx_chain=-1):
    vec3 = ctypes.c_float * 3
    _Get_Translation_Vectors(p_state, vec3(*ta), vec3(*tb), vec3(*tc), idx_image, idx_chain)

### Get Translation Vectors
_Get_Dimensionality          = _core.Geometry_Get_Dimensionality
_Get_Dimensionality.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int]
_Get_Dimensionality.restype  = ctypes.c_int
def Get_Dimensionality(p_state, idx_image=-1, idx_chain=-1):
    vec3 = ctypes.c_float * 3
    return int(_Get_Dimensionality(p_state, idx_image, idx_chain))