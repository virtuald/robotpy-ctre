
import re

def function_hook(fn, data):
    '''Called for each function in the header'''
    
    m = re.match(r'c_%s_(.*)' % data['module_name'], fn['name'])
    if not m:
        raise Exception("Unexpected fn %s" % fn['name'])
    
    x_name = m.group(1)
    if x_name.startswith('Create'):
        x_name = '__init__'
    
    x_name = x_name[0].lower() + x_name[1:]
    
    py_self_comma = ', '
    if len(fn['parameters']) == 1:
        py_self_comma = ''
    
    # wrap.cpp.j2 stuff
    returns = fn['returns']
    
    x_in_params = []
    x_out_params = []
    
    # parameter names, types
    
    # inner call
    
    # return
    
    x_ret_names = []
    x_ret_types = []
    
    for p in fn['parameters'][1:]:
        p['x_decl'] = '%s %s' % (p['raw_type'], p['name'])
        
        if p['pointer']:
            x_out_params.append(p)
        else:
            x_in_params.append(p) 
    
    # if there are out params, then change returns to be a tuple
    if x_out_params:
        p = ','.join([p['raw_type'] for p in x_out_params])
        returns = 'std::tuple<%s, %s>' % (fn['returns'], p)
    
    x_callend = ''
    x_return = ''
    
    if returns == 'void':
        x_callstart = ''
    else:
        if returns == 'CTR_Code':
            x_callstart = 'auto __ret = CheckCTRCode('
            x_callend = ')'
        else:
            x_callstart = 'auto __ret = '
            
        if x_out_params:
            x_return = 'return std::make_tuple(__ret, %s);'
        else:
            x_return = 'return __ret;'
    
    # x_calldecls
    x_refdecls = ''
    if x_out_params:
        x_refdecls = ['%s %s']
    
    # x_call_params
    
    # lazy :)
    fn.update(locals())
        
    

