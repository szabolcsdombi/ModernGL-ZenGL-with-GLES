import moderngl

import mymodule

mymodule.init()

ctx = moderngl.create_context(context=mymodule, require=300)

print('Vendor: %(GL_VENDOR)s\nRenderer: %(GL_RENDERER)s\nVersion: %(GL_VERSION)s' % ctx.info)

prog = ctx.program(
    vertex_shader='''
        #version 310 es
        precision highp float;

        vec2 vertex[3] = vec2[](
            vec2(1.0, 0.0),
            vec2(-0.5, -0.86),
            vec2(-0.5, 0.86)
        );

        vec3 color[3] = vec3[](
            vec3(0.0, 0.0, 1.0),
            vec3(0.0, 1.0, 0.0),
            vec3(1.0, 0.0, 0.0)
        );

        out vec3 v_color;
        void main() {
            v_color = color[gl_VertexID];
            float r = float(gl_InstanceID - 4) * 0.15;
            mat2 rot = mat2(cos(r), sin(r), -sin(r), cos(r));
            gl_Position = vec4(rot * vertex[gl_VertexID] * 0.95 * vec2(9.0 / 16.0, 1.0), 0.0, 1.0);
        }
    '''.strip(),
    fragment_shader='''
        #version 310 es
        precision highp float;

        in vec3 v_color;
        out vec4 f_color;

        void main() {
            f_color = vec4(pow(v_color, vec3(1.0 / 2.2)), 1.0);
        }
    '''.strip(),
)

vao = ctx.vertex_array(prog, [])
vao.instances = 9
vao.vertices = 3

while mymodule.update():
    ctx.clear(0.0, 0.0, 0.0, 0.0)
    vao.render()
