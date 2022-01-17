<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <script>
            import { useState, useEffect, useRef, useCallback } from 'react'
    import * as THREE from 'three'
    import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls'
    import { loadGLTFModel } from '../lib/model'
    import { DogSpinner, DogContainer } from './voxel-dog-loader'

    function easeOutCirc(x) {
    return Math.sqrt(1 - Math.pow(x - 1, 4))
    }

    const VoxelDog = () => {
    const refContainer = useRef()
    const [loading, setLoading] = useState(true)
    const [renderer, setRenderer] = useState()
    const [_camera, setCamera] = useState()
    const [target] = useState(new THREE.Vector3(-0.5, 1.2, 0))
    const [initialCameraPosition] = useState(
        new THREE.Vector3(
        20 * Math.sin(0.2 * Math.PI),
        10,
        20 * Math.cos(0.2 * Math.PI)
        )
    )
    const [scene] = useState(new THREE.Scene())
    const [_controls, setControls] = useState()

    const handleWindowResize = useCallback(() => {
        const { current: container } = refContainer
        if (container && renderer) {
        const scW = container.clientWidth
        const scH = container.clientHeight

        renderer.setSize(scW, scH)
        }
    }, [renderer])

    /* eslint-disable react-hooks/exhaustive-deps */
    useEffect(() => {
        const { current: container } = refContainer
        if (container && !renderer) {
        const scW = container.clientWidth
        const scH = container.clientHeight

        const renderer = new THREE.WebGLRenderer({
            antialias: true,
            alpha: true
        })
        renderer.setPixelRatio(window.devicePixelRatio)
        renderer.setSize(scW, scH)
        renderer.outputEncoding = THREE.sRGBEncoding
        container.appendChild(renderer.domElement)
        setRenderer(renderer)

        // 640 -> 240
        // 8   -> 6
        const scale = scH * 0.005 + 4.8
        const camera = new THREE.OrthographicCamera(
            -scale,
            scale,
            scale,
            -scale,
            0.01,
            50000
        )
        camera.position.copy(initialCameraPosition)
        camera.lookAt(target)
        setCamera(camera)

        const ambientLight = new THREE.AmbientLight(0xcccccc, 1)
        scene.add(ambientLight)

        const controls = new OrbitControls(camera, renderer.domElement)
        controls.autoRotate = true
        controls.target = target
        setControls(controls)

        loadGLTFModel(scene, '/dog.glb', {
            receiveShadow: false,
            castShadow: false
        }).then(() => {
            animate()
            setLoading(false)
        })

        let req = null
        let frame = 0
        const animate = () => {
            req = requestAnimationFrame(animate)

            frame = frame <= 100 ? frame + 1 : frame

            if (frame <= 100) {
            const p = initialCameraPosition
            const rotSpeed = -easeOutCirc(frame / 120) * Math.PI * 20

            camera.position.y = 10
            camera.position.x =
                p.x * Math.cos(rotSpeed) + p.z * Math.sin(rotSpeed)
            camera.position.z =
                p.z * Math.cos(rotSpeed) - p.x * Math.sin(rotSpeed)
            camera.lookAt(target)
            } else {
            controls.update()
            }

            renderer.render(scene, camera)
        }

        return () => {
            console.log('unmount')
            cancelAnimationFrame(req)
            renderer.dispose()
        }
        }
    }, [])

    useEffect(() => {
        window.addEventListener('resize', handleWindowResize, false)
        return () => {
        window.removeEventListener('resize', handleWindowResize, false)
        }
    }, [renderer, handleWindowResize])

    return (
        <DogContainer ref={refContainer}>{loading && <DogSpinner />}</DogContainer>
    )
    }

    </script>
    <p align="center"><img src="https://i.giphy.com/RThN0hOS2GO4M.gif" /></p>
    <h1> C-Programing-Basic</h1>
    <h2>C Basic Lab Term - Ha Noi University Of Technology & Sciencies</h2>
    <h2> Lecturer: PhD. Tran Hong Viet</h2>
    <h4>1. FILE</h4>
    <h4>2. LINKED LIST</h4>
    <h4>3. STACK & QUEUE</h4>
    <h4>4. TREE</h4>
    <h4>5. SORT (Seclection, Insertion, Buble, Heap, Merge, Quick )</h4>
    <h4>6. SEARCHING</h4>
    <h4>7. STRING PATTERN MATCHING </h4>
    <h4>HASH TABLE</h4>
</body>
</html>
